a=list(map(int,input().split()))
print("bust" if sum(a)>21 else "win")