def q(a,h):
 d[a]=str(h)
 for b in t[a]:q(b,h+1)
t,p,d={},{},{}
for _ in[0]*int(input()):
 e=input().split()
 t[e[0]]=e[2:]
 for i in e[2:]:p[i]=e[0]
r=(set(t)-set(p)).pop()
p[r]='-1'
q(r,0)
print('\n'.join(f"node {i}: parent = {p[i]}, depth = {d[i]}, {'root'if'-1'==p[i]else'internal node'if t[i]else'leaf'}, [{', '.join(t[i])}]"for i in map(str,sorted(map(int,t)))))
