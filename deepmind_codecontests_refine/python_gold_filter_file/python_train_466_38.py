l1=list(map(int,input().split()))
l3=[500,1000,1500,2000,2500]
l2=list(map(int,input().split()))
x,y=map(int,input().split())
score=x*100-y*50
for j in range(5):
    score+=max(0.3*l3[j],(250-l1[j])*(l3[j]//250)-50*l2[j])
print(int(score))