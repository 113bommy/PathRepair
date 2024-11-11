n,s=open(0);a=i=j=0
while j<int(n):
 if s[i:j]in s[j:]:a=max(a,j-i);j+=1
 else:i+=1
print(a)