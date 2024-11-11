n=int(input())
al=sorted(list(map(int,input().split())),reverse=True)
print(sum(al[::2]) - sum(al[1::2]))