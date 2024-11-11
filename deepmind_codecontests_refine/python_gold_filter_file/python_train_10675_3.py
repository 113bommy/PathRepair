s = input().lstrip('0')

if s.find('.') != -1:
	s = s.rstrip('0')

po = s.find('.')
if po == -1:
	po = len(s) - 1
elif po == 0:
	po = -1
	s = s[1:]
	for i in range(len(s)):
		if s[i] == '0':
			po -= 1
		else:
			break
	s = s[-po-1:]
else:
	po = len(s[:po]) - 1
	
s = s.replace('.', '')


if len(s) == 0:
	print('0')
else:
	print(s[0] + ('.' if len(s[1:].rstrip('0')) > 0 else '') + s[1:].rstrip('0') + ('E' + str(po) if po != 0 else ''))
