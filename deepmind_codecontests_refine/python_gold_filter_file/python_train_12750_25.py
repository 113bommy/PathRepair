n=input()
l=input()
a=""
t=[a,a,"2","3","223","5","53","7","7222","7332"]
for i in l:
    a+=t[int(i)]
print("".join(sorted(a)[::-1]))
