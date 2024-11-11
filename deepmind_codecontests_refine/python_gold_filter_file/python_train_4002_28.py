import re
s = input()
low = re.search('[abcdefghijklmnopqrstuvwxyz]{1}',s)
r = 'Too weak'
if not low or low.endpos <= low.pos or len(s) < 5:
   print(r)
else:
   low = re.search('[ABCDEFGHIJKLMNOPQRSTUVWXYZ]{1}',s)
   if not low or low.endpos <= low.pos:
      print(r)
   else:
      low = re.search('[\d]{1}',s)
      if not low or low.endpos <= low.pos:
         print(r)
      else:
         print('Correct')