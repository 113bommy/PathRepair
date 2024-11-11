import sys
input()
s=sys.stdin.read()
x=s.find('OO')
print('NO' if x<0 else 'YES\n'+s[:x]+'++'+s[x+2:])