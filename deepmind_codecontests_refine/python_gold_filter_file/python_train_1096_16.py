__author__ = 'zihaozhu'
from sys import stdin

cases = int(stdin.readline())

numbers = list(map(int,stdin.readline().split()))


int1=0
intn=0


for i in range(0,len(numbers)):
    if numbers[i] == 1:
        int1=i+1
    if numbers[i] == cases:
        intn=i+1
#print(int1)
#print(intn)
maxDist = abs(intn-int1)

if(maxDist == cases-1):
    print (maxDist)
    exit(0)
if(abs(int1-1)>maxDist):
    maxDist=abs(int1-1)
if(abs(int1-cases)>maxDist):
    maxDist=abs(int1-cases)
if(abs(intn-1)>maxDist):
    maxDist=abs(intn-1)
if(abs(intn-cases)>maxDist):
    maxDist=abs(intn-cases)
print (maxDist)
"""maxDist1 = abs(numbers[cases-1]-numbers[0])
maxDist = 0

for i in range (0,len(numbers)):
    if(abs(numbers[cases-1]-numbers[i])>maxDist1):
        maxDist1=abs(numbers[cases-1]-numbers[i])
        maxDist=abs((cases-1)-(i))
for i in range(len(numbers)-1,-1,-1):
    if(abs(numbers[i]-numbers[0]>maxDist1)):
        maxDist1=abs(numbers[i]-numbers[0])
        maxDist=abs((cases-1)-(i))
print (maxDist)
"""