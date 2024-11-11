from collections import Counter
a=input()
b=input()
if Counter(a)==Counter(b):
    print(-1 if a==b else len(a))
else:
    print(len(a) if len(a)>len(b) else len(b))