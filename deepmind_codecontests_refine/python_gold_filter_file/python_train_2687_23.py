import re
print(len(max(re.split('[^ACGT]',input()),key=len)))