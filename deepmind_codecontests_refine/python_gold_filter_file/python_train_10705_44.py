s = input()
print("Yes" if int(s)%sum(map(int,s))==0 else "No")