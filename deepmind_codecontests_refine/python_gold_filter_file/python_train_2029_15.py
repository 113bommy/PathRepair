string = input()
print('YES'
      if ('AB' in string
          and 'BA' in string.replace('AB', '-', 1))
      or ('BA' in string
          and 'AB' in string.replace('BA', '-', 1))
      else 'NO')
