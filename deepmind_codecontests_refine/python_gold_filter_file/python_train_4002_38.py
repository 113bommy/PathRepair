import re
s=input()
print(["Too weak","Correct"][all([len(s)>=5,re.search('[a-z]', s),re.search('[A-Z]', s),re.search('\d', s)])])