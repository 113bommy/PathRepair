n , t = map( int , input().split() )
bus = []
for i in range(n):
    s , d = map(int , input().split() )
    if s>=t:
        bus.append(s)
    else:
        temp = ((t-s)//d)*d + s
        if temp<t:
            temp = temp+d
        if t//d==0:
            temp = s+d

        bus.append(temp)
x = bus.index(min(bus))
print(x+1)