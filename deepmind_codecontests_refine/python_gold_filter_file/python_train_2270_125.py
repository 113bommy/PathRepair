n, k = [int(i)-1 for i in input().split()]
s = input()
print(s[:k]+s[k].lower()+s[k+1:])
