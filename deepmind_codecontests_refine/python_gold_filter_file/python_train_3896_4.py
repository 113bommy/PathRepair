#-------------------------------#
#INCLUDE <Amirhossein_Alimirzaei>
#INCLUDE <HajLorenzo>
#INCLUDE <ESSI.H>
#-------------------------------#


a=list(map(int,input().split()))
res = 2
res-= a[0]==a[2]
res-= a[1]==a[3]
print(res,end=" ")
res=2
black1 = (a[0]+a[1]) % 2 != 0
black2 = (a[2]+a[3]) % 2 != 0
if black1 != black2 or (a[0] == a[2] and a[1] == a[3]):
    print(0,end=" ")
else:
    print(1 if abs(a[0]-a[2]) == abs(a[1]-a[3]) else 2,end=" ")

print(abs(a[0] - a[2]) +  max(abs(a[1] - a[3]) - (abs(a[0] - a[2])),0))


