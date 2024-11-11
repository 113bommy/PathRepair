s=input()
d=""
n=int(input())
for i in range((len(s)+n-1)//n):
	d+=s[i*n]
print(d)