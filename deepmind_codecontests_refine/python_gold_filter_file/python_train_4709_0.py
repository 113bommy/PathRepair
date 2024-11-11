mstr=input()
r=mstr
if mstr==mstr.upper():
	r=mstr.lower()
def left(s, amount):
    return s[:amount]
def right(s, amount):
    return s[-amount:]
le=left(mstr,1)
ri=right(mstr,len(mstr)-1)
if le==le.lower() and ri == ri.upper():
	r=mstr.title()
if len(mstr) == 1 and mstr.lower()==mstr:
	r=mstr.upper()
print(r)