n=int(input())
l=set(map(int,input().split()))
print(sorted(l)[1] if len(l)>1 else 'NO')