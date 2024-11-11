
N = int(input())
List = sorted([abs(int(i)) for i in input().split()])

l = len(List) - 2
r = len(List) - 1
answer = 0

while(l > -1):

	while( 2*List[l] >= List[r] and l >  -1):
		l -= 1

	if(l >= 0):
		answer += (r-1-l)
		r -= 1

	if(l == -1):
		answer += (r)*(r+1)/2
		break

print(int(answer))