from itertools import *
def f(s):
 if sum(s)==10:return"((({} + {}) + {}) + {})".format(*s)
 for a,b,c,d in permutations(s):
  for x,y,z in permutations('+-*'*2,3):
   for t in[f"({a} {x} {b}) {y} ({c} {z} {d})",f"(({a} {x} {b}) {y} {c}) {z} {d}",f"({a} {x} ({b} {y} {c})) {z} {d}"]:
    if eval(t)==10:return'('+t+')'
 else:return 0
for e in iter(input,'0 0 0 0'):print(f(list(map(int,e.split()))))
