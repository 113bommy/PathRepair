import re

def revPolish(f):
    f = re.sub(r'(\-?\d+\.?\d*?)\s(\-?\d+\.?\d*?)\s([\+\-\*/])(?!\d)',
        lambda m: str(eval(m.group(1) + m.group(3) + m.group(2))),
        f)
    if f[-1] in ('+','-','*','/'):
        return revPolish(f)
    else:
        return f

print(revPolish(input()))
