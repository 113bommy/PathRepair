n=int(input())
d,x=map(int,input().split())
print(x+sum([(d-1)//int(input())+1 for i in range(n)]))