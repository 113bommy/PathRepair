from sys import stdin
e = [map(int,x.rstrip().split()) for x in stdin.readlines()][1]
p, c = 0,0
for x in e:
    if x > 0:
        p+=x
    elif p == 0:
        c+= x
    else:
        p+=x
print (-1*c)
