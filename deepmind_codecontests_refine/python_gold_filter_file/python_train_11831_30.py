import sys

s = sys.stdin.readline().strip()
cont = 0
for x in range(len(s)):
	if s[x]=='a' or s[x]=='e' or s[x]=='i' or s[x]=='o' or s[x]=='u' or s[x]=='1' or s[x]=='3' or s[x]=='5' or s[x]=='7' or s[x]=='9':
		cont=cont+1
print (cont)
