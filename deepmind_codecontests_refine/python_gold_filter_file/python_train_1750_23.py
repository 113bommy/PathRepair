H,W,N = map(int, input().split())
st = [int(i) for i in input().split()]
S = input()
T = input()


def simu(dim1):
    now = [st[0],st[1]]

    if dim1 == 'U':
        dim2,L,step,dim = 'D',H,1,0
    if dim1 == 'D':
        dim2,L,step,dim = 'U',H,-1,0
    if dim1 == 'L':
        dim2,L,step,dim = 'R',W,1,1
    if dim1 == 'R':
        dim2,L,step,dim = 'L',W,-1,1

    for i in range(N):
        if S[i] == dim1:
            now[dim] -= step
        if now[dim] < 1 or now[dim] >= L+1:
            return True
        if T[i] == dim2:
            if step == 1:
                if now[dim] < L:
                    now[dim] += step
            else:
                if now[dim] > 1:
                    now[dim] += step
    return False
        
Dim = ['U','D','L','R']
for d in Dim:
    if simu(d):
        print('NO')
        exit()
print('YES')
