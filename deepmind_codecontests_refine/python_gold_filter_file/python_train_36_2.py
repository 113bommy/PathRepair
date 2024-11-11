from sys import stdin, stdout

n = int(stdin.readline())
s = stdin.readline()
 
s = list(s)
if s.count('I')==0:
    stdout.write(str(s.count('A')))
elif s.count('I')==1:
    stdout.write('1')
else:
    stdout.write('0')