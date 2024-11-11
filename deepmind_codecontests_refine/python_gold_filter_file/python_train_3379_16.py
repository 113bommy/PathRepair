n=int(input())
x=input().split()[1:]
y=input().split()[1:]
print(['Oh, my keyboard!','I become the guy.'][len(set(x+y))==n])