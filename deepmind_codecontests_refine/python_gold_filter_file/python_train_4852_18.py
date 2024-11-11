import math
sides, angle=list(map(int, input().split(" ")))

def findClosest(n,a):
	totalAngle=(n-2)*180/n;
	closest=n-2;
	diff=math.fabs(totalAngle-a);
	for x in range (1, n-2):
		angle=x/(n-2)*totalAngle;
		newDiff=math.fabs(angle-a)
		if(newDiff<diff):
			closest=x;
			diff=newDiff
	print(2, 1, 2+closest)

findClosest(sides,angle)