s=input();u=s.upper();l=s.lower()
print(''.join([(u[i],l[i])[s[i]==u[i]]for i in range(len(s))]))