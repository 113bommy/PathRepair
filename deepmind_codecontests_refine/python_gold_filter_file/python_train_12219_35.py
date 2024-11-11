n=input()
n=int(n)
sets=list(map(int,input().split(" ")))
muscles={"chest":0,"biceps":0,"back":0}
for i in range(0,n):
    if (i%3==2):
        muscles["back"]+=sets[i]
    elif (i%3==1):
        muscles["biceps"]+=sets[i]
    else:
        muscles["chest"]+=sets[i]

for key in muscles.keys():
    if muscles[key]==max(muscles.values()):
        print(key)

