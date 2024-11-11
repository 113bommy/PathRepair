start=input()
end=input()
colst =start[0]
if colst=="a":
    colst=1
elif colst=="b":
    colst=2
elif colst=="c":
    colst=3
elif colst=="d":
    colst=4
elif colst=="e":
    colst=5
elif colst=="f":
    colst=6
elif colst=="g":
    colst=7
elif colst=="h":
    colst=8
rowst=int(start[1])
cole=end[0]
if cole=="a":
    cole=1
elif cole=="b":
    cole=2
elif cole=="c":
    cole=3
elif cole=="d":
    cole=4
elif cole=="e":
    cole=5
elif cole=="f":
    cole=6
elif cole=="g":
    cole=7
elif cole=="h":
    cole=8
rowe=int(end[1])
d=[]
cnt=0

while((colst!=cole)or(rowst!=rowe)):
    ans=""

    if colst<cole:
        ans+="R"
        colst+=1
    if colst>cole:
        ans+="L"
        colst-=1
    if rowst < rowe:
        ans += "U"
        rowst += 1
    if rowst > rowe:
        ans += "D"
        rowst -= 1
    cnt+=1
    d.append(ans)
print(cnt)
for i in d:
    print(i)


