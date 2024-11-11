n,k= map(int,input().split())
a = [int(x) for x in input().split() if int(x)<=5-k]
print(len(a)//3)
