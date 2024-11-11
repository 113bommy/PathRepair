s,t=input(),input();l,m=len(s),len(t)
for i in range(l-m+1):
 if all(c in"?"+d for c,d in zip(s[-i-m:],t)):s=s.replace(*"?a");exit(print(s[:-i-m]+t+s[l-i:]))
print("UNRESTORABLE")