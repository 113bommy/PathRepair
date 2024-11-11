N,x = map(int,input().split())
if x in {1,2*N-1}:print("No")
else:
    print("Yes")
    if x>=N:
        ans = list(range(N,x))+list(range(x+1,2*N)) + [x] + list(range(1,N))
    else:
        ans = list(range(N+1,2*N)) + [x] + list(range(1,x)) + list(range(x+1,N+1))
    print("\n".join(map(str,ans)))