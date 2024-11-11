h={"":0};
for i in[1,-1]:
    for _ in range(int(input())):
        s=input()
        if s in h:h[s]+=i
        else:h[s]=i
print(max(h.values()))