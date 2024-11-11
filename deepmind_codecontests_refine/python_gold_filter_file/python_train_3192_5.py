N=int(input()) #take the size

Array=list(map(str,input().split()[:N]))

s=''.join(Array)



C = s.find('CC')

M = s.find('MM')


Y = s.find('YY')

a = s.find('C?Y')
b = s.find('C?M')
c = s.find('M?Y')
d = s.find('M?C')
e = s.find('Y?C')
f = s.find('Y?M')
g=s.find('?')
h = s.find('C?C')
i = s.find('Y?Y')
j = s.find('M?M')
k = s.find('??')
l = s.find('???')
m = s.find('????')
n = s.find('?????')
o = s.find('??????')


if (Y ==-1 and M ==-1 and C ==-1 and a==-1 and b==-1 and c==-1 and d==-1 and e==-1 and f==-1 and g!= -1) or (( a!=-1 or b!=-1 or c!=-1 or d!=-1 or e!=-1 or f!=-1)and(h!=-1 or i!=-1 or j!=-1 or k!=-1 or l!=-1 or m!=-1 or n!=-1 or o!=-1 or g==0)):
    print("Yes")
else:
    print("No")    
    