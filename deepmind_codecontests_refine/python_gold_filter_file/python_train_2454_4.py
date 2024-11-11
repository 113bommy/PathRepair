import sys
#sys.stdin = open('input', 'r');
a = int(input())
b = int(input())
c = int(input())
if (a + b + c < 7) or (b < 2 and c < 4):
   print(0)
   sys.exit()
while a * 2 > b:
   a -= 1
while a * 4 > c:
   a -= 1
sys.stdout.write(str(a + 2 * a + 4 * a) + '\n')
