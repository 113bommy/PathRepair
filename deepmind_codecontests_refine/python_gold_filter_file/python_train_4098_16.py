import re
m = re.match(r"^\w{1,16}@(?P<hostname>\w{1,16}(?:\.\w{1,16})*)(?:\/\w{1,16})?$", input())
print("NO" if m == None or len(m.group("hostname")) > 32 else "YES")