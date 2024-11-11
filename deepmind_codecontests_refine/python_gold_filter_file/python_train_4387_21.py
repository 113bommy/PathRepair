def mi():
    return map(int, input().split())
'''
def gcd (a,b):
	if b==0:
		return a
	return gcd(b,a%b)

AS
2H 4C TH JH AD
'''
s = list(input())

cards = ['2','3','4','5','6','7','8','9','T','J','Q','K','A']

inp = input().split()
for i in range(5):
    inp[i] = list(inp[i])

for i in inp:
    if i[1]==s[1]:
        print ('YES')
        exit(0)
    if cards.index(s[0])==cards.index(i[0]):
        print ('YES')
        exit(0)
print ('NO')
