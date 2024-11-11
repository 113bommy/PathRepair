n=int(input())
ar=list(map(int,input().split()))
ar=sorted(ar)
print(ar[(n+1)//2-1])


