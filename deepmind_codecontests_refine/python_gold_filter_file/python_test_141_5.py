t = int(input())
for _ in range(t):
    A, S = map(str, input().split())
    A = list(A)
    S = list(S)
    A = [int(c) for c in A]
    S = [int(c) for c in S]
    A.reverse()
    #S.reverse()
    #print(A)
    #print(S)
    B = []
    flag = True
    for a in A:
        if len(S) == 0:
            flag = False
            break
        else:
            if S[-1] >= a:
                b = S[-1]-a
                B.append(b)
                S.pop()
            else:
                if len(S) <= 1:
                    flag = False
                    break
                s = S[-1]+S[-2]*10
                b =s-a
                if b >= 10 or b < 0:
                    flag = False
                    break
                B.append(b)
                S.pop()
                S.pop()
    #print(B)
    #print(S)
    if not flag:
        print(-1)
        continue
    while S:
        b = S.pop()
        B.append(b)
    #if not B:
        #print(-1)
        #continue
    #B.reverse()
    ans = 0
    for i, b in enumerate(B):
        ans += b*pow(10, i)
    print(ans)
    #B = [str(c) for c in B]
    #B = ''.join(B)
    #B = int(B)
    #print(B)
