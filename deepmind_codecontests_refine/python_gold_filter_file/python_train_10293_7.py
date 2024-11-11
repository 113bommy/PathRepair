N=int(input())
*a,=map(int,input().split())
print(min([sum(map(lambda x:(x-n)**2,a)),n] for n in range(-100,101))[0])
