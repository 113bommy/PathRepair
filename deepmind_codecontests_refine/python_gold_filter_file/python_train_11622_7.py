n = int(input())
# print(n);
a = set();
while(n):
    s = input();
    s = s.replace('u', 'oo');
    s = s.replace('oo', 'u');
    t = s;
    s = s.replace('kh', 'h');
    while(t!=s):
        t = s;
        s = s.replace('kh', 'h');
    a.add(s);
    n-=1;
print(len(a))
