N,P=map(int,input().split())
maxfac = round(P**(1/N))
# print(range(1,maxfac+1))
if N==1:
    print(P)
    exit()
for i in range(1,maxfac+1)[::-1]:
    p = i**N
    # print(P%p)
    if P%p == 0:
        print(i)
        break
