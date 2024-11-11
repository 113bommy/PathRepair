p=[int(i) for i in input().split()]
if p[4]<=p[2]<=p[0]-p[4] and p[4]<=p[3]<=p[1]-p[4]:print("Yes")
else: print("No")
