import sys
lines = (sys.stdin.readlines())[0]
abu = lines.strip()
mohamad = set(abu)
if len(mohamad) % 2 == 0:
    print('CHAT WITH HER!')
else:
    print('IGNORE HIM!')