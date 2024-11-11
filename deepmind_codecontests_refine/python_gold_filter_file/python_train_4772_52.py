s=input()
t=input()

if sorted(s)<sorted(t)[::-1]:
    print('Yes')
else:
    print('No')