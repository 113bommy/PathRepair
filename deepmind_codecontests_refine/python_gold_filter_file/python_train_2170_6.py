n=int(input())
a=list(map(int,input().split()))
e=sum(x%2==0 for x in a)
print(3**n-2**e)