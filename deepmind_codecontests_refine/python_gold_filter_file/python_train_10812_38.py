s=input();K=int(input());n=""
for c in s:
 i=(123-ord(c))%26
 if K>=i:n+="a";K-=i
 else:n+=c
print(n[:-1]+chr((ord(n[-1])-97+K)%26+97))