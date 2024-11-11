s=input()

BW=s[::2]
WB=s[1::2]

x=BW.count("0") + WB.count("1")
y=BW.count("1") + WB.count("0")

print(min(x,y))