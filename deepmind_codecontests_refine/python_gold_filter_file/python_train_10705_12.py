x=int(input())
print("Yes" if x%sum(map(int,str(x)))==0 else "No")