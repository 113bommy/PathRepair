import re
a= input()
text=input()
rep={"RU":"D","UR":"D"}
rep = dict((re.escape(k), v) for k, v in rep.items())
pattern = re.compile("|".join(rep.keys()))
text = pattern.sub(lambda m: rep[re.escape(m.group(0))], text)
print(len(text))