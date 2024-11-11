n = int(input())
s = input()
assert len(s) == n
for c in "CMY":
	if c*2 in s:
		print("No")
		exit()
if s.startswith("?") or s.endswith("?"):
	print("Yes")
	exit()
if '??' in s:
	print("Yes")
	exit()
for c in "CMY":
	if '?'.join((c, c)) in s:
		print("Yes")
#
		exit()
print("No")
__test__ = '''
CY??Y
C?C?Y
?CYC?
C??MM
MMY
'''