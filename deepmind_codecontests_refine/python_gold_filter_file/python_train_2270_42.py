k = int(input().split()[1])
s = input()
print(s[0:k-1]+s[k-1:k].lower()+s[k:len(s)+1])