n=int(input())
s=str(input())
n=len(s)
vowels = ['a','e','i','o','u','y']
j=0
for i in range(n):
    i-=j
    if i<=(n-2) and i+1<len(s):
        if s[i] in vowels and s[i+1] in vowels:
           s=s[:i+1]+s[i+2:]
           j=j+1
print(s)