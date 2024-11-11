from sys import stdin
    
n,m,k=map(int,stdin.readline().split())
arr=sorted(list(map(int,stdin.readline().split())),reverse=True)
a=arr[0]
b=arr[1]
x=m//(k+1)
y=m-((k+1)*x)
print((a*((k*x)+y))+(b*x))

