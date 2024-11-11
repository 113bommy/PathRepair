s,k = map(int,input().split())
n = list(input())
if s == 1:
    if k == 1 :
        print(0)
    else:
        print(n[0])
    
else:
    if n[0] > '1' and k>0:
        n[0] = '1'
        k = k-1
    i = 1
    while k>0 and i <s:
        if n[i] != '0':
            n[i] = '0'
            k = k-1
        i += 1
    print("".join(n))