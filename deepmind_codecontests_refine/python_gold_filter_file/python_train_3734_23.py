S=input()
print("Yes" if all([S.count(i)%2==0 for i in set(S)]) else "No")